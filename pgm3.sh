read -p "Enter value of n:" n
sum=0
for ((i=1; i<=n; i++));
do
	sum=$(expr $sum + $i)
done
echo "The sum of the first $n numbers:$sum"
