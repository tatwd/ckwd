#ifndef __FRACTION_H__
#define __FRACTION_H__

int checkFra(int fz,int fm);        //判断分数
int GCD(int fz,int fm);             //求最大公约数
void reduFra(int fz,int fm);        //通分
void achReduFra(int fz,int fm);     //实现通分

int checkFra(int fz,int fm){
    int flag;
    
    if (fm ==0 ){
        printf("Error:fm=0!\n");
        return flag = 0;
    }
    else return flag = 1;
}

int GCD(int fz,int fm){
    int temp,r;
    int gcd;    //最大公约数gcd
    if(fz < fm){
        temp = fz;
        fz = fm;
        fm = temp;
    }
    r = fz % fm;
    while (r != 0){
        fz = fm;
        fm = r;
        r = fz % fm;
    }
    return gcd = fm;
}

void reduFra(int fz,int fm){
    int a = fz,b =fm;
    int gcd;    //最大公约数gcd
    int newfz,newfm;
       
    gcd = GCD(a,b);
    
    newfz = fz / gcd;
    newfm = fm / gcd;        
    
    /*
     * 统一输出形式，如：1/2 or -1/2.
     *
     * 只需判断newfm的正负即可：
     * if nwefm < 0 {
     *      nwefm <<-- -newfm;
     *      newfz <<-- -newfz;
     * }
     * else 不变;
     */
    
    if(newfm < 0){
         newfz = -newfz;
         newfm = -newfm;
    }
    printf("Reduction of it is %d/%d\n",newfz,newfm);
}
void achReduFra(int fz,int fm){
    int a =fz,b = fm;
    int flag;
    //int t;
    
    //printf("Input a fraction(first fz,next fm):\n");
    //scanf("%d%d",&a,&b);

    flag = checkFra(a,b);
    
    if(a != 0){    

    	while(flag != 1){
        	printf("Please input agin:\n");
        	scanf("%d%d",&a,&b);        
        	flag = checkFra(a,b);
        	//t = a;
    	}
        
        if(a != 0){
    	    printf("The fraction is %d/%d.\n",a,b);
            reduFra(a,b);
        }
        else
            printf("The fraction is 0.\n");
    } 
    else
        printf("The fraction is 0.\n");
}
#endif
