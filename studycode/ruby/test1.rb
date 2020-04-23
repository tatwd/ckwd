#!/usr/bin/ruby -w
#-*- coding: utf-8 -*-
=begin
这是注释
=end

puts "Hello, Ruby!";
puts "你好，世界！";

END{
    puts "last see me."
}
BEGIN{
    puts "first see me."
}
#interger整型字面量
#字面量（literal）:可见的值
a1 = 0
a2 = 1_000_000 #带千分符
a3 = 0xa #十六进制
#a1,a2,a3 = 0, 1_000_000,0xa 并行赋值

f1 = 0.0
f2 = 2.1
f3 = 1000000.1
#f1,f2=f2,f1 并行交换参数值

puts a1,a2
puts a3
puts f1,f2,f3

puts 2**(1/4) #2^(1/4)=2^0=1
puts 16**(1/4.0) #16^(0.25)=16的四次方根=2.0

puts 'escape using "\\"';
puts 'That \'s right';

puts "mutiplication value:#{24*60*60}";
name="Ruby"
puts name
puts "#{name+",ok"}"

desc1 = %Q{ruby的字符串可以使用''和""。}
desc2 = %q|ruby的字符串可以使用''和""。|
puts desc1
puts desc2

str = String.new("THIS IS TEST")
foo = str.downcase #大写转小写
puts "#{foo}"

ary = ["fred",10,3.14,"This is a string","last element",]
ary.each do |i|
    puts i
end

d1 = Array.[](1,2,3,4)
d2 = Array[1,3,5]
d3 = Array.new(10){
    |e|e = e*2
}
digits = Array(0..9)
num = digits.at(6)
puts "#{d1}"
puts "#{d2}"
puts "#{d3}"
puts "#{digits}"
puts "#{num}"

hsh = colors ={
    "red"=>0xf00,
    "green"=>0x0f0,
    "blue"=>0x00f,
    #[1,"jan"]=>"January"
}
hsh.each do |key,value|
    print key," is ",value,"\n"
end
puts "#{hsh['red']}"

(10..15).each do |n|
    print n,' '
end
print "\n"

a=2
b=a<<2
puts b

puts defined? foo
puts defined? $_
puts defined? bar

if a == 4 then a = 7 end #一行内写出完整的if式，加then

if a>3
    puts "a 大于 2"
 elsif a<3 and a!=1
    puts "a 是 2"
 else
    puts "无法得知a的值"
end

puts "条件为真" if a<3

unless b>2
    puts "b x小于 2"
  else
    puts "b 大于 2"
end

puts "条件为假" unless b<2

case a when a==4 then a=7 end

$age = 6
case $age
when 0..2
    puts "婴儿"
when 3..6
    puts "小孩"
when 7..12
    puts "child"
when 13..18
    puts "少年"
else
    puts "其他"
end

#当case的"表达式"部分被省略时，将计算第一个when条件部分为真的表达式.
fool = false
bar = true
quu = false

case
when fool then puts 'fool is true'
when bar then puts 'bar is true'
when quu then puts 'quu is true'
end

#do 或 : 可以省略不写。但若要在一行内写出 while 式，则必须以 do 或 : 隔开条件式或程式区块。
$i = 0
$num = 5
while $i < $num do
    puts("在循环语句中 i = #$i")
    $i += 1
end

begin
    puts("在循环语句中 num = #$num")
    $num += 1
end while $num < 8

#语法中 do 可以省略不写。但若要在一行内写出 until 式，则必须以 do 隔开条件式或程式区块。
until $i > $num do
    puts("i = #$i")
    $i += 1
end

#break终止最内部的循环。如果在块内调用，则终止相关块的方法（方法返回 nil）。
for i in 0..5
    if i>2 then
        break
    end
    puts "局部变量i=#{i}"
end

#next跳到循环的下一个迭代。如果在块内调用，则终止块的执行（yield 表达式返回 nil）。
(0..5).each do |i|
    if i < 2 then
        next
    end
    puts "局部变量i=#{i}"
end
