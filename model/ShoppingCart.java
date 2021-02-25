package model;

import java.util.ArrayList;

public class ShoppingCart {
    private Customer customer;
    private ArrayList<Product> products = new ArrayList<Product>();

    public ShoppingCart(Customer c) {
        this.customer = c;
    }

    public Customer getCustomer() {
        return customer;
    }

    public void buy(Product p) {
        System.out.println(p.getType() + ", name " + p.getTitle() + " cost " + p.getPrice());
        products.add(p);

    }

    /*
     * public void removeProduct(int index){ Product p=products.get(index);
     * System.out.println(p.getTitle()+" is remove"); products.remove(index); }
     */
    public void removeProduct(Product p) {
        try {
            if (products.contains(p)) {
                products.remove(p);
                System.out.println(p.getTitle() + " is remove");
            } else {
                throw (new Exception());
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public int searchPriceByTitle(String title) {
        int price = 0;
        for (int i = 0; i < products.size(); i++) {
            if (products.get(i).getTitle() == title) {
                price = products.get(i).getPrice();
            }
        }
        return price;
    }

    public int getTotal() {
        Product p;
        int total = 0;
        for (int i = 0; i < products.size(); i++) {
            p = products.get(i);
            total = total + p.getPrice();
        }
        return total;
    }

    public void printAllProduct() {
        Product p;
        for (int i = 0; i < products.size(); i++) {
            p = products.get(i);
            System.out.println("Product name:" + p.getTitle() + " price:" + p.getPrice());
        }
    }

}
