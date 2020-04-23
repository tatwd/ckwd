// 1、冒泡排序

// 循环的最大值从length递减
// 基本就是每次循环只能排好最后一个 然后递减到第一个
 
  function bubbleSort(){
  var changedData = new Array();
  var index = 0;
      console.log("冒泡调用");
      for (var j = a.length; j >0 ; j--) {
          for (var i = 0; i < j; i++) {
              if(a[i]>a[i+1]){
                  var z = 0;
                  z = a[i+1];
                  a[i+1] = a[i];
                  a[i] = z;
              }
              changedData[index] = a.toString();
              index++;
          }//one            
      }//two
      showDateChange(changedData);
  }
  
// 2、选择排序

// 外循环 j选取当前元素 到length-1
// 内循环 j+1开始 到length 逐个比较出最小值min
// 交换 min 和 a[j]

function selectionSort(){
var changedData = new Array();
var index = 0;
    console.log("选择调用");
    for (var j = 0; j < a.length-1; j++) {
        var min = a[j];
        var minIndex = j;
        for (var i = j+1; i < a.length; i++) {
            if(a[i] < min) {
                min = a[i];
                minIndex = i;
            }
        }//one
        a[minIndex] = a[j];
        a[j] = min;
        // 
        changedData[index] = a.toString();
        index++;
    }//two
    showDateChange(changedData);
}
// 3、插入排序

// 从下标1开始 往后选择直到最后
// 每个选中的和他前面的所有比较
// 直到找到比他小的 排在他后面
// 相当于从1开始 每次都排好之前的i+1个 直到length
// 和冒泡相反

function insertionSort(){
var changedData = new Array();
var index = 0;
    console.log("插入排序");
    for (var j = 1; j < a.length; j++) {
        var now = a[j];
        var i = j - 1;
        while(i>=0 && now<a[i]){
            // 向后移数组
            a[i+1] = a[i];
            i--;
        }//one
        a[i+1] = now;
        changedData[index] = a.toString();
        index++;
    }//two
    showDateChange(changedData);
}
// 4、希尔排序

// 间隔改变的插入排序
// 传统插入排序 比较前面的相邻对象
// 希尔排序比较前面的第h个对象 直到h间隔不存在更改
// 改变h 直到 h=1

function shellSort(){
var changedData = new Array();
var index = 0;
    console.log("希尔排序");
    var N = a.length;
    var h = 1;
    if (h < N/3) {
        h = h*3 + 1;//设置间隔
    }
    while(h > 0){
        for (var j = h; j < a.length; j++) {
            for (var i = j;i >= h && a[i] < a[i-h]; i -= h) {
                var z;
                z = a[i];
                a[i] = a[i-h];
                a[i-h] = z;
                // 
                changedData[index] = a.toString();
                index++;
            }
        }
        h = (h-1)/3;//改变间隔
    }
    showDateChange(changedData);
}
// 5、归并排序

// 数据分为 step为间隔的小数组
// 将小数组排序 step变大 直到为1/2个数组
// 将前后两个已排序的数组 再排序

function mergeSort(arr){
var changedData = new Array();
    console.log("归并排序");
    if (arr.length < 2) {
        return;
    }
    var step = 1;
    var left;
    var right;
    while(step < arr.length){
        left = 0;
        right = step;
        while(right + step <= arr.length){
            mergeArrays(arr,left,left+step,right,right+step);
            left = right + step;
            right = left + step;
        }
        if (right < arr.length) {
            mergeArrays(arr,left,left+step,right,arr.length);
        }
        step *= 2;
    }
    function mergeArrays(arr,startLeft,stopLeft,startRight,stopRight){
        var leftArray = new Array(stopLeft - startLeft +1);
        var rightArray = new Array(stopRight - startRight +1);
        k = startRight;
        for (var i = 0; i < rightArray.length-1; i++) {
            rightArray[i] = arr[k];
            k++;
        }
        k = startLeft;
        for (var i = 0; i < leftArray.length-1; i++) {
            leftArray[i] = arr[k];
            k++;
        }
        rightArray[rightArray.length-1] = Infinity;
        leftArray[leftArray.length-1] = Infinity;
        var m = 0;
        var n = 0;
        for (var k = startLeft; k < stopRight; k++) {
            if (leftArray[m] <= rightArray[n]) {
                arr[k] = leftArray[m];
                m++;
            }else{
                arr[k] = rightArray[n];
                n++;    
            }
        }
        arr += "";//转化为字符串
        changedData.push(arr);
    }
    showDateChange(changedData);
}
// 6、快速排序

// 没实现可视化排序

function quickSort(){
    console.log("快速排序");
    function qSort(list){
        if (list.length == 0) {
            return list;
        }
        // 选取基数
        var pivotIndex = Math.floor(list.length/2);
        var pivot = list.splice(pivotIndex,1)[0];

        var left = [];
        var right = [];
        for (var i = 0; i < list.length; i++) {
            if (list[i] > pivot) {
                right.push(list[i]);
            }else{
                left.push(list[i]);
            }
        }
        // 递归 更换基数 并且排序其左右
        return qSort(left).concat([pivot],qSort(right));
    }
    a = qSort(a);
    showDate();
}