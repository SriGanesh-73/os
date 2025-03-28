fibonacci() {
    if [ $1 -le 1 ]; then
        echo $1
    else
        prev1=$(fibonacci $(( $1 - 1 )))
        prev2=$(fibonacci $(( $1 - 2 )))
        echo $(( prev1 + prev2 ))
    fi
}
fibonacci_series() {
    read -p "Enter the number of terms: " n
    for ((i=0; i<n; i++)); do
        echo -n "$(fibonacci $i) "
    done
    echo 
}

fibonacci_series

