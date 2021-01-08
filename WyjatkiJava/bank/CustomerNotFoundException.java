package bank;

public class CustomerNotFoundException extends Exception{
    static final long serialVersionUID = 1L;
    private String surname;

    CustomerNotFoundException(){ }

    CustomerNotFoundException(String errorMsg, String sname){
        super(errorMsg);
        surname = sname;
    }

    public String getSurename(){
        return surname;
    }
    
}
