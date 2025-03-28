display_array_min_max() {
    arr=("$@")
    min=${arr[0]}
    max=${arr[0]}
    for num in "${arr[@]}"; do
        if [ $num -lt $min ]; then
            min=$num
        fi
        if [ $num -gt $max ]; then
            max=$num
        fi
    done
    echo "Array: ${arr[@]}"
    echo "Minimum: $min"
    echo "Maximum: $max"
}
array=()
read -p "Enter n:" n
for (( i=0; i<n; i++));
do
	read -p "Enter element $((i + 1)):" value
	array+=("$value")
done
display_array_min_max "${array[@]}"
