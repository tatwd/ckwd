#!/usr/bin/ruby -w
#-*- coding: utf-8 -*-

#创建类及方法
class Customer
    @@no_of_customers=0
    def initialize(id,name,addr)
        @cust_id=id
        @cust_name=name
        @cust_addr=addr
    end
    def display()
        puts "Customer id: #@cust_id"
        puts "Name: #@cust_name"
        puts "Address: #@cust_addr"
    end
    def total()
        @@no_of_customers+=1
        puts "Total number of customers:#@@no_of_customers"
    end
    def speak()
        puts "Hello,I am #@cust_name!"
    end
end

#创建对象
cust1 = Customer.new("1","John","Wisdom Apartments,Ludhiya")
cust2 = Customer.new("2","Poul","New Empire road,Khandala")

#调用方法
cust1.display()
cust1.total()
cust1.speak()
cust2.display()
cust2.total()
cust2.speak()
