display_array(){
	arr=("$@")
	echo "Array Elements:"
	for element in "${arr[@]}"
	do
		echo "$element"
	done
}
array=()
read -p "How many elements do you want to enter?:" n
echo "Enter $n elements:"
for (( i=0; i<n; i++))
do
	read -p "Enter elements $((i + 1)):" value
	array+=("$value")
done
display_array "${array[@]}"

