let mx = 100001
let arr = [0, 4, -9, 3, 7, 1, 0, 2];
let tree = []

function init(node, b, e) {
    if (e == b) {
        tree[node] = arr[b];
        return
    }
    let left = node * 2
    let right = node * 2 + 1
    let mid = parseInt((b + e) / 2)
    init(left, b, mid);
    init(right, mid + 1, e);
    tree[node] = tree[left] + tree[right]
}

init(1, 1, arr.length - 1);

function query(node, b, e, i, j) {
    if (i > e || j < b)
        return 0;
    if (b >= i && e <= j)
        return tree[node];
    let left = node * 2, right = node * 2 + 1;
    let mid = (b + e) / 2
    return query(left, b, mid, i, j) + query(right, mid + 1, e, i, j);
}

// [0, 4, -9, 3, 7, 1, 0, 2];
function update(node, b, e, i, value) {
    if (e == b) {
        tree[node] = value;
        return;
    }
    let left = node * 2, right = node * 2 + 1;
    let mid = parseInt((b + e) / 2)
    if (i > mid)
        update(right, mid + 1, e, i, value)
    else
        update(left, b, mid, i, value)

    tree[node] = tree[left] + tree[right];
}

function update2(node, b, e, i, newvalue) {
    if (i > e || i < b)
        return 0;
    if (b >= i && e <= i) {
        node[node] = newvalue;
        return
    }
    let left = node * 2, right = node * 2 + 1;
    let mid = parseInt((b + e) / 2)
    update2(left, b, mid, i, value)
    update2(right, mid + 1, e, i, value)
    tree[node] = tree[left] + tree[right];
}


// update(1, 1, 7, 2, 1);

console.log(query(1, 1, 7, 2, 6));