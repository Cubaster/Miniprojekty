package bank;

public class Account {
    private int accountNumber;
    private Customer owner;
    private double balance;
    private int password;
    private String login;

    public Account(){
        balance = 0;
        login = "";
    }

    public Account(int n, Customer c, String l, int p){
        this.accountNumber = n;
        this.owner = c;
        this.balance = 100;
        this.password = p;
        this.login = l;
    }
    
   public void login(String login, int passwd) throws AccountLoginFailedException {
       if(login.equals(this.login) && passwd == this.password){
            System.out.println("Access granted");
       }
       else{
            if(login.equals(this.login))
                throw new AccountLoginFailedException("Wrong password", passwd);
            if(passwd == this.password)
                throw new AccountLoginFailedException("Wrong login", login);
            else
                throw new AccountLoginFailedException("Wrong login and password", login, passwd);
       }

    }

    public Customer getCustomer(){
        return this.owner;
    }

    public int getNumber(){
        return this.accountNumber;
    }

    public double getBalance(){
        return this.balance;
    }

    public boolean pay(double amount){
        if(amount < 0 ) return false;
        this.balance += amount;
        return true;
    }

    public boolean payoff(double amount){
        if(amount < 0 || this.balance < amount) return false;
        this.balance -= amount;
        return true;
    }

    public double showFunds(){
        return balance;
    }

    public static void main(String args[]){
        Customer c1 = new Customer("Tom", "Code");
        Account a1 = new Account(100, c1, "cust1", 579314);
        try{
        a1.login("cust1", 579314);
        }
        catch(AccountLoginFailedException e){
                System.out.println(e);
        }
    }



}
