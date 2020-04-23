package bin;
import java.util.*;

public class MyCalendar {

	/**
	 * @author RestingPasser
	 * @param args
	 */
	public static void main(String[] args) {
		
		GregorianCalendar now = new GregorianCalendar();

		//获取一个Date对象
		Date date = new Date();
		System.out.println(date.toString());

		//设置now的值
		now.setTime(date);

		//从now中取出日期、月份
		int today = now.get(Calendar.DAY_OF_MONTH);
		int month = now.get(Calendar.MONTH);
		//System.out.println(today+" "+month);

		//设置now的日期为1
		now.set(Calendar.DAY_OF_MONTH, 1);
		
		//得到now是一周的第几天
		int week = now.get(Calendar.DAY_OF_WEEK);
		System.out.println("Sun	Mon	Tue	Wed	Thu	Fri	Sat");

		//打印出 前面的空格
		for(int i = Calendar.SUNDAY;i < week;i++){
			System.out.print("	");
		}
		while(now.get(Calendar.MONTH) == month){
			int day = now.get(Calendar.DAY_OF_MONTH);

			//为了对齐，要对大于10和小于10的数打印不同的空格数
			if(day < 10){
				if(day == today)
					System.out.print("-" + day + "-	");
				else
					System.out.print(" " + day + "	");
			}
			else{
				if(day == today)
					System.out.print("-" + day + "-	");
				else
					System.out.print("" + day + "	");
			}
			//周六换行
			if(week == Calendar.SATURDAY){
				System.out.println();
			}
			
			//增加一天
			now.add(Calendar.DAY_OF_MONTH, 1);
			week = now.get(Calendar.DAY_OF_WEEK);
		}
	}

}
