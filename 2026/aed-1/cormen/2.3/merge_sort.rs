fn merge(a: &mut [i32], p: usize, q: usize, r: usize) {
    let n_l = q - p + 1;
    let n_r = r - q;
    let mut l = vec![0; n_l];
    let mut r = vec![0; n_r];

    for i in 0..n_l {
        l[i] = a[p + i];
    }

    for i in 0..n_r {
        r[i] = a[q + i + 1];
    }

    let mut i = 0;
    let mut j = 0;
    let mut k = p;

    while i < n_l && j < n_r {
        if l[i] <= r[j] {
            a[k] = l[i];
            i = i + 1;
            k = k + 1;
        } else {
            a[k] = r[j];
            j = j + 1;
            k = k + 1;
        }
    }

    while i < n_l {
        a[k] = l[i];
        i = i + 1;
        k = k + 1;
    }

    while j < n_r {
        a[k] = r[j];
        j = j + 1;
        k = k + 1;
    }
}

fn merge_sort(a: &mut [i32], p: usize, r: usize) {
    if p >= r {
        return;
    }

    let q = (p + r) / 2;

    merge_sort(a, p, q);
    merge_sort(a, q + 1, r);
    merge(a, p, q, r);
}

fn main() {
    let mut a = [4, 3, 1, 6, 10];
    let p = 0;
    let r = 4;

    println!("Unsorted.");

    for i in &a {
        println!("{}", i);
    }

    merge_sort(&mut a, p, r);

    println!("Sorted.");

    for i in &a {
        println!("{}", i);
    }
}
