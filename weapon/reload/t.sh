for i in {0..83}; do
    old_index=$((i + 147))
    new_index=$i
    mv img${old_index}.png img${new_index}.png
done

