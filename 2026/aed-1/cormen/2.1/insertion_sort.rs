fn insertion_sort(a: &mut [i32], n: usize) {
    for i in 1..n {
        let key = a[i];
        let mut j = i;
        while j > 0 && a[j - 1] > key {
            a[j] = a[j - 1];
            j -= 1;
        }
        a[j] = key;
    }
}

fn main() {
    let mut a = [4, 3, 1, 6, 10];
    let n = a.len();

    println!("Unsorted.");

    for i in &a {
        println!("{}", i);
    }

    insertion_sort(&mut a, n);

    println!("Sorted.");

    for i in &a {
        println!("{}", i);
    }
}
