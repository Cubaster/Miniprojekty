package recycling;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Scanner;
import java.util.TreeMap;

public class Wezel{
    @Deprecated
    @Override
    protected void finalize() throws Throwable{
        System.out.println("Finalizowanie obiektu");
        super.finalize();
    }

    ArrayList<Wezel> polaczenia = new ArrayList<>();
    HashMap<Wezel, Boolean> next = new HashMap<>();
    TreeMap<Wezel, Boolean> relate = new TreeMap<Wezel, Boolean>(new Comparator<Wezel>(){
      public int compare(Wezel o1 , Wezel o2)  
        {
            return o1.getName().compareTo(o2.getName());
        }
    });

    String selfname;

    Wezel(String name){
        this.selfname = name;
    }
    public String getName(){
        return this.selfname;
    }

    public void dodajPolaczenie(Wezel w){
        this.polaczenia.add(w);
    }

    public void relation(Wezel w, Boolean next){
        this.next.put(w, next);
    }

    public void isNext(Wezel w){
        if(this.next.get(w))
            System.out.println("Hash connected");
        else
            System.out.println("Hash not connected");
    }

    public void orderedRelation(Wezel w, Boolean next){
        this.relate.put(w, next);
    }

    public void isNextTree(Wezel w){
        if(this.relate.get(w))
            System.out.println("Tree connected");
        else
            System.out.println("Tree not connected");
    }

    
    public static void main(String[] args) {
        
        Scanner s = new Scanner(System.in);
        for (int i=0; i<= 100000; i++){
            Wezel w1 = new Wezel("w1");
            Wezel w2 = new Wezel("w2");
            w1.dodajPolaczenie(w2);
            w2.dodajPolaczenie(w1);
            System.out.println(w1.polaczenia);
            System.out.println(w2.polaczenia);
            Wezel w3 = new Wezel("w3");
            Wezel w4 = new Wezel("w4");
            w3.relation(w4, true);
            w4.relation(w3, false);
            w3.isNext(w4);
            w4.isNext(w3);
           
        }
        Wezel w5 = new Wezel("w5");
        Wezel w6 = new Wezel("w6");
        w5.orderedRelation(w6, false);
        w6.orderedRelation(w5, true);
        w5.isNextTree(w6);
        w6.isNextTree(w5);
        s.nextLine();
        s.close();
    }
}

// 10000 iterations result: "Finalizowanie obiektu" not printed, user can type sth on terminal
// after "Enter" press program ends

// 1000000 iterations result: Program prints "Finalizowanie obiektu" and allow user to type sth on terminal
// after "Enter" press program ends


// there are references between w1 and w2 but as excepition was thrown w1 and w2 become null references so 
// GC removed them

// List, unlike dynamic ArrayList, is static collection and when exception is thrown
// it changes List indexing and cause errors

// HashMap allow fast access to collection memebers ( do not have to be unique)

//TreeMap sorted collection fast access to its members but each member has to be unique 