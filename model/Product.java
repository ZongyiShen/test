package model;

public class Product {
    private String type;
    private String title;
    private int price;
    public Product(String ty,String ti,int p) {
    	this.type=ty;
    	this.title=ti;
    	this.price=p;
    }
    public String getType(){
        return this.type;
    }
    public String getTitle(){
        return this.title;
    }
    public int getPrice(){
        return this.price;
    }

}
