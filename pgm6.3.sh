fibo(){
	echo -n "$1 "
	if [ $2 -eq $3 ];
	then
		echo
	else
		echo $(fibo $2 $(($1 + $2)) $3)
	fi
}
read -p "Enter n:" n
fibo 0 1 $n
