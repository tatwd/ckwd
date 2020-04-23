"use strict"	//严格模式

function testFun1(){
	var x = document.getElementById("d1");
	x.innerHTML="Hello JavaScript";
}

function testFun2(){
	var y = document.getElementById("numb").value;	// 获取 id="numb" 的值
	var text;
	if(isNaN(y) || y<1 || y>10){
		text = "输入错误";
	}else{
		text = "输入正确";	
	}
	document.getElementById("d2").innerHTML = text;
	//alert(text);
}	

// 外部无用，内部有用
// document.getElementById("myBtn").onclick=function(){displayDate()};
// function displayDate(){
// 	document.getElementById("d3").innerHTML=Date();
// }
window.onload = function(){
	document.getElementById("myBtn").onclick=function(){displayDate()};
	function displayDate(){
		document.getElementById("d3").innerHTML=Date();
	}
}
