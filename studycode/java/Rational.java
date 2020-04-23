package bin;
    /*
    	这是有理数中分数的类，包含了关于它的基本运算：
    	  加法：add();	减法：sub();
    	  乘法：muti();	除法：div();
    */

public class Rational{
    int numerator;	//分子
    int denominator;    //分母
    
    Rational(){
    }
    Rational(int a,int b){
        if(a == 0){
            numerator = 0;
            denominator = 1;
        }else{
            setNumeAndDeno(a,b);
        }
    }
    //设置分子和分母
    void setNumeAndDeno(int a,int b){
        int c = f(Math.abs(a),Math.abs(b)); //计算最大公约数
        numerator = a/c;
        denominator = b/c;
        if(numerator < 0 && denominator < 0){
            numerator = -numerator;
            denominator = -numerator;
        }
    }
    
    int getNume(){
        return numerator;
    }
    int getDeno(){
        return denominator;
    }
    //求a和b的最大公约数
    int f(int a,int b){
        if(a < b){
            //交换a和b的值
            int c = a;
            a = b;
            b = c;
        }
        int r = a % b;  //求余
        while(r != 0){
            a = b;
            b = r;
            r = a % b;
        }
        return b;
    }
    //加法运算
    Rational add(Rational r){
        int a = r.getNume();
        int b = r.getDeno();
        int newNume = numerator * b + denominator * a;
        int newDeno = denominator * b;
        Rational result = new Rational(newNume,newDeno);
        return result;
    }
    //减法运算
    Rational sub(Rational r){
        int a = r.getNume();
        int b = r.getDeno();
        int newNume = numerator * b - denominator * a;
        int newDeno = denominator * b;
        Rational result = new Rational(newNume,newDeno);
        return result;
    }
    //乘法运算
    Rational muti(Rational r){
        int a = r.getNume();
        int b = r.getDeno();
        int newNume = numerator * a;
        int newDeno = denominator * b;
        Rational result = new Rational(newNume,newDeno);
        return result;
    }
    //除法运算
    Rational div(Rational r){
        int a = r.getNume();
        int b = r.getDeno();
        int newNume = numerator * b;
        int newDeno = denominator * a;
        Rational result = new Rational(newNume,newDeno);
        return result;
    }

}
