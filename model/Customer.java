package model;

public class Customer {
    private String name;
    private String passwd;
    private int vip;
    private int point;
    public Customer(){
        name="jar";
        passwd="1234";
        vip=1;
        point = 99999;
    }
    public Customer(String n,String pwd,int v,int p){
        this.name=n;
        this.passwd=pwd;
        this.vip=v;
        this.point = p;
    }
    public String getName(){
        return this.name;
    }
    public String getPasswd(){
        return this.passwd;
    }
    public int getVip(){
        return this.vip;
    }
    public int getPoint(){
        return this.point;
    }
    public void pay(int cost){
        if(vip == 1){
            cost=(int)(cost*0.8);
        }
        point=point-cost;
    }
    public void setVip(int i){
        this.vip=i;
    }
}
