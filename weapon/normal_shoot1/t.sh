for i in {1..12}; do
    old_index=$(printf "%d" $i)
    new_index=$(printf "%d" $((i - 1)))
    mv img${old_index}.png img${new_index}.png
done

