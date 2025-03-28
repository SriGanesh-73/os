fibo(){
	read -p "Enter the number of terms in fibonacci series:" n
	a=0
	b=1
	echo "Fibonacci Series upto $n terms:"
	for((i=0; i<n; i++));
	do
		echo -n "$a "
		sum=$((a + b))
		a=$b
		b=$sum
	done
	echo
}
fibo
