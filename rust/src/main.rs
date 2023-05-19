struct Solution;
#[allow(unused_imports)]
use std::collections::*;

impl Solution {
    pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut cnt = vec![0; 20001];
        for x in nums {
            cnt[(x + 10000) as usize] += 1;
        }
        let mut heap = BinaryHeap::<(i32, i32)>::from(
            cnt.into_iter()
                .enumerate()
                .filter(|&(_, x)| x > 0)
                .map(|(i, x)| (x, i as i32 - 10000))
                .collect::<Vec<_>>(),
        );
        let mut ans = vec![];
        for _ in 0..k {
            ans.push(heap.pop().unwrap().1 as i32);
        }
        ans
    }
}

fn main() {}
