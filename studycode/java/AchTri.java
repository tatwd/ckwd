/*
 *  File Name: AchTri.java
 *  Author: RestingPasser
 *  Created Time: 2016.11.19 19:17:16
 */

package bin;
import cls.Triangle;    //引用cls文件夹下的Triangle类

public class AchTri{
    public static void main(String args[]){
        Triangle tri = new Triangle(12,-3,100);
        tri.计算面积();
        tri.修改三边(3,4,5);
        tri.计算面积();
    }
}

