package bank;

import java.util.ArrayList;

interface SearchCustomers{
    Customer findByName(String name) throws CustomerNotFoundException;
}

interface SearchAccounts{
    Account findByNumber(int number) throws AccountNotFoundException;
    ArrayList<Account> findAllCustomerAccounts(Customer cust) throws AccountNotFoundException;
}

public class Bank implements SearchAccounts, SearchCustomers {
    ArrayList<Customer> customers = new ArrayList<Customer>();
    ArrayList<Account> accounts = new ArrayList<Account>();


    public Bank(){ }

    @Override
    public Customer findByName(String sname) throws CustomerNotFoundException{
        for(int i = 0; i < customers.size(); i++){
            if(customers.get(i).getSname().equals(sname)){
                return customers.get(i);
            }
        }
        throw new CustomerNotFoundException("Customer not found", sname);
    }

    @Override
    public Account findByNumber(int num) throws AccountNotFoundException{
        for(int i = 0; i < accounts.size(); i++){
            if(accounts.get(i).getNumber() == num){
                return accounts.get(i);
            }
        }
        throw new AccountNotFoundException("Account not found", num);
    }

    @Override
    public ArrayList <Account> findAllCustomerAccounts(Customer cust) throws AccountNotFoundException{
        ArrayList <Account> custacc = new ArrayList<Account>();
        for(int i = 0; i < accounts.size(); i++){
            if(cust.getPesel().equals(accounts.get(i).getCustomer().getPesel())){
                custacc.add(accounts.get(i));
            }
        }
        if(!custacc.isEmpty()) return custacc;
        throw new AccountNotFoundException("Customer has no accounts", cust);
    }

    public boolean addCustomer(Customer c){
        if(!c.getPesel().equals("") && !c.getSname().equals("")){
            System.out.println("Customer added");
            customers.add(c);
            return true;
        }
        System.out.println("Cannot add customer unknown user or invalid PESEL");
        return false;
    }

    public boolean addAccount(Account a){
        if(customers.contains(a.getCustomer())){
            System.out.println("Account added");
            accounts.add(a);
            return true;
        }
        System.out.println("Cannot add! Owner unknown");
        return false;
    }

    public void showCustomers(){
        System.out.print(customers);
    }

    public void showAccounts(){
        System.out.print(accounts);
    }

    public static void main(String args[]) throws CustomerNotFoundException {
        Bank b = new Bank();
        Customer c1 = new Customer("BoB", "Jones");
        Customer c2 = new Customer("Tom", "Byte");
        Customer c3 = new Customer("Ann", "Long");
        Customer c4 = new Customer("Peny", "Save");
        Account a1 = new Account(123,c1,"cust1", 43252);
        Account a2 = new Account(134,c2,"cust1", 43252);
        Account a3 = new Account(145,c2,"cust1", 43252);
        Account a4 = new Account(176,c4,"cust1", 43252); //invalid Account - not owner 
        c1.setPesel("12345678901");
        c2.setPesel("23456789012");
        c3.setPesel("34567890123");
        c4.setPesel("ssdffgsd354"); // invalid Pesel
        b.addCustomer(c4); // cannot add Customer with invalid pesel
        b.addCustomer(c3);
        b.addCustomer(c1);
        b.addAccount(a3); // cannot create account if owner is not Bank Customer
        b.addCustomer(c2);
        b.addAccount(a3); // !"cannot create account if owner is not Bank Customer" - Customer added operation valid 
        b.addAccount(a1);
        b.addAccount(a2);
        b.addAccount(a4); // Owner is not Bank Customer cannot create Account
        // Customer
        try{
            b.findByName("Jones");
            System.out.println("Jones is Bank Customer");
        }
        catch(CustomerNotFoundException e){
            System.out.println(e.getSurename() + " is not Customer");
        }
        try{
            b.findByName("Save");
            System.out.println("Save is Bank Customer");
        }
        catch(CustomerNotFoundException e){
            System.out.println(e.getSurename() + " is not Customer");
        }
        // Account by number
        try{
            b.findByNumber(134);
            System.out.println("Account number 134 exists in Bank");
        }
        catch(AccountNotFoundException e){
            System.out.println("No account number:" + e.getNumber());
        }
        try{
            b.findByNumber(176);
            System.out.println("Account number 176 exists in Bank");
        }
        catch(AccountNotFoundException e){
            System.out.println("No account number:" + e.getNumber());
        }
        // Account by owner
        try{
            ArrayList<Account> acc;
            acc = b.findAllCustomerAccounts(c2);
            System.out.println("Customer has Account/s: " + acc);
        }
        catch(AccountNotFoundException e){
            System.out.println("No accounts for this Customer:" + e.getCustomer());
        }
        try{
            ArrayList<Account> acc;
            acc = b.findAllCustomerAccounts(c3);
            System.out.println("Customer has Account/s: " + acc);
        }
        catch(AccountNotFoundException e){
            System.out.println("No accounts of: " + e.getCustomer().getSname());
        }
        // printStack
        try{
            b.findByName("Jones");
            System.out.println("Jones is Bank Customer");
        }
        catch(CustomerNotFoundException e){
            e.printStackTrace(System.out);
        }
        try{
            b.findByName("Save");
            System.out.println("Save is Bank Customer");
        }
        catch(CustomerNotFoundException e){
            e.printStackTrace(System.out);
        }
        // print fillIn
        try{
            b.findByName("Jones");
            System.out.println("Jones is Bank Customer");
        }
        catch(CustomerNotFoundException e){
            e.printStackTrace(System.out);
            e.fillInStackTrace();
            throw e;
        }
        try{
            b.findByName("Save");
            System.out.println("Save is Bank Customer");
        }
        catch(CustomerNotFoundException e){
            e.printStackTrace(System.out);
            e.fillInStackTrace();
            throw e;
        }


    }

    
}


// When programmer uses interfaces it allows him write methods which can be use in many classes
// with simillar mechanics. For example " Interface with method introduce", this method can be implemented
// in classes Person, Worker, Student but in each is overriden in different way to fits best for each class


// Both output define by me and output with printStackTrace refere to the same piece of code

//After adding only fillInStackTrace nothing has changed. Since adding throw line below fillInStackTrace
// throws CustomerNotFound had to be added to main declaration and the same exception is called twice
// but ones programmer get info about function call and exception and second info only about exception
// General stack trace is replaced by current stack frame. FillIn prevent track building its a good practice
// it reduces resources consumption