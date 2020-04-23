package bin;    //.class储存文件夹

public class PalinNum{
    public static void main(String[] args){
    
        /* 打印:	*/
        /*   1		*/
        /*   121	*/
        /*   12321	*/
        /*   1234321	*/
       
	int i,j,k;
        
        for (i = 1;i <= 4;i++){
            System.out.print("\n");
            
            for (j = 1;j < i;j++){
                System.out.print(j);
            }
            
            for (k = j;k > 0;k--){
                System.out.print(k);
            }
        }
        System.out.println();
    }
}
