package bin;

public class AchRat {
	public static void main(String args[]) {
		
        Rational r1 = new Rational(1, 5);
        Rational r2 = new Rational(3, 2);

        //测试加法
        Rational result = r1.add(r2);
        int a = result.getNume();
        int b = result.getDeno();
        System.out.println("1/5 + 3/2 = " + a + "/" + b);

        //测试减法
        result = r1.sub(r2);
        a = result.getNume();
        b = result.getDeno();
        System.out.println("1/5 - 3/2 = " + a + "/" + b);

        //测试乘法
        result = r1.muti(r2);
        a = result.getNume();
        b = result.getDeno();
        System.out.println("1/5 x 3/2 = " + a + "/" + b);

        //测试除法
        result = r1.div(r2);
        a = result.getNume();
        b = result.getDeno();
        System.out.println("1/5 / 3/2 = " + a + "/" + b);
       
        //求2/1 + 3/2 + 5/3 + 8/5 + 13/8 +...的前n项和
        int n = 10,k = 1;
        System.out.println("计算2/1 + 3/2 + 5/3 + 8/5 + 13/8 +..." + n + "项和." );
        Rational sum = new Rational(0,1);
        Rational item = new Rational(2,1);
        while (k <= n){
            sum = sum.add(item);
            k++;
            int fz = item.getNume();
            int fm = item.getDeno();
            item.setNumeAndDeno(fz + fm,fz);
        }
        a = sum.getNume();
        b = sum.getDeno();
        System.out.println("用分数表示：");
        System.out.println("Sn = " + a + "/" + b);
        double doubleResult = (a * 1.0) / b;
        System.out.println("用小数表示：");
        System.out.println("Sn = " + doubleResult);
    }
}
