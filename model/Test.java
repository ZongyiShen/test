package model;

public class Test {
    public static void main(String[] args) {
        int total;
        Customer c1 = new Customer();
        Customer c2 = new Customer("jjjjar", "1234", 0, 1000);
        ShoppingCart s1 = new ShoppingCart(c1);
        Product p1 = new Product("Book", "C++", 150);
        Product p2 = new Product("Book", "Java", 100);
        s1.buy(p2);
        s1.buy(p1);
        s1.printAllProduct();
        String bookname = "C++";
        System.out.println(bookname + " price is " + s1.searchPriceByTitle(bookname));
        s1.removeProduct(p1);
        s1.removeProduct(p1);
        total = s1.getTotal();
        Product p3 = new Product("Dog", "Peter", 1000);
        s1.buy(p3);
        s1.printAllProduct();
        System.out.println("Your cost is " + total);
        c1.pay(total);
        if (c1.getVip() == 1) {
            System.out.println("You will get discount");
        } else {
            System.out.println("You will not get discount");
        }
        c1.setVip(0);
        System.out.println(s1.getCustomer().getName() + " input password " + s1.getCustomer().getPasswd());
        System.out.println("Hello " + s1.getCustomer().getName() + " your point is " + c1.getPoint());
        c2.pay(20);
        System.out.println("Hello " + c2.getName() + " your point is " + c2.getPoint());
    }
}
