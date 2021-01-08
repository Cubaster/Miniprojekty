package bank;

public class AccountNotFoundException extends Exception {
    static final long serialVersionUID = 1L;
    private int number;
    private transient Customer customer;

    AccountNotFoundException(){ }

    AccountNotFoundException(String errorMsg, int num, Customer cust){
        super(errorMsg);
        number = num;
        customer = cust;
    }

    AccountNotFoundException(String errorMsg, int num){
        super(errorMsg);
        number = num;
    }

    AccountNotFoundException(String errorMsg, Customer cust){
        super(errorMsg);
        customer = cust;
    }
    
    public int getNumber(){
        return number;
    }

    public Customer getCustomer(){
        return customer;
    }
}
