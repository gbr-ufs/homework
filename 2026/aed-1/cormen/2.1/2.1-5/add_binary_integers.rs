fn add_binary_integers(a: &[i32], b: &[i32], n: usize) -> Vec<i32> {
    let mut c = vec![0; n + 1];
    let mut sum = 0;

    for i in 0..n - 1 {
        sum += a[i] * 1 << i;
        sum += b[i] * 1 << i;
    }

    let mut i = 0;

    while sum != 0 {
        c[i] = sum % 2;
        sum /= 2;
        i += 1;
    }

    return c;
}

fn main() {
    let a = [1, 0, 0, 0, 0];
    let b = [1, 1, 0, 0, 0];
    let n = 5;
    let c = add_binary_integers(&a, &b, n);

    for i in 0..n - 1 {
        println!("{}", c[i]);
    }
}
