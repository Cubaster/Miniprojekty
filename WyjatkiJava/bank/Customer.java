package bank;

public class Customer{
        String name;
        String surname;
        String address;
        String pesel;
        
        protected static boolean isAlpha(String s){
            return s != null && s.matches("[a-zA-Z0-9]+");
        }

        protected static boolean isDigit(String p){
            return p != null && p.matches("[0-9]{11}");
        }

        public Customer(){
            name = "";
            surname = "";
            address = "";
            pesel = "";
        }

        public Customer(String name, String surname){
            this.name = name;
            this.surname = surname;
            this.address = "";
            this.pesel = "";
        }

        public String getName(){
            return name;
        }

        public String getSname(){
            return surname;
        }

        public boolean setAddress(String address) {
            if(isAlpha(address)){
            this.address = address;
            return true;
            }
            System.out.println("Address not set!");
            return false;
        }

        public String getAddress(){
            return address;
        }

        public boolean setPesel(String pesel) {
            if(isDigit(pesel)){
            this.pesel = pesel;
            System.out.println("Pesel set!");
            return true;
            }
            System.out.println("Pesel not set!");
            return false;
        }

        public String getPesel(){
            return pesel;
        }

        @Override
        public boolean equals(Object c){

            Customer o = (Customer) c;
            if(!(c instanceof Customer)){
                return false;
            }
            if(this.surname.length() == o.surname.length()){
                for(int i=0; i < this.surname.length(); i++){
                    if(this.surname.charAt(i) != o.surname.charAt(i))
                        return false;
                }
                return true;

            }
            return false;
        }

        public static void main(String args[]){
            Customer c1  = new Customer("Bob", "Robe");
            Customer c2  = new Customer("Cob", "Robe");
            c1.setPesel("01234567890");
            if(c1.equals(c2)){
                System.out.println("The same");
            }
            else{
            System.out.println("Different");
            }
        }



}

// Override allows programmer to redifine functionality of yet existing method. Argument list and returned
// type should be the same as they are in basic method but implementtion can differ