<h2><a href="https://leetcode.com/problems/next-greater-element-i">496. Next Greater Element I</a></h2><h3>Easy</h3><hr><p>The <strong>next greater element</strong> of some element <code>x</code> in an array is the <strong>first greater</strong> element that is <strong>to the right</strong> of <code>x</code> in the same array.</p>

<p>You are given two <strong>distinct 0-indexed</strong> integer arrays <code>nums1</code> and <code>nums2</code>, where <code>nums1</code> is a subset of <code>nums2</code>.</p>

<p>For each <code>0 &lt;= i &lt; nums1.length</code>, find the index <code>j</code> such that <code>nums1[i] == nums2[j]</code> and determine the <strong>next greater element</strong> of <code>nums2[j]</code> in <code>nums2</code>. If there is no next greater element, then the answer for this query is <code>-1</code>.</p>

<p>Return <em>an array </em><code>ans</code><em> of length </em><code>nums1.length</code><em> such that </em><code>ans[i]</code><em> is the <strong>next greater element</strong> as described above.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [4,1,2], nums2 = [1,3,4,2]
<strong>Output:</strong> [-1,3,-1]
<strong>Explanation:</strong> The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,<u>4</u>,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [<u>1</u>,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,<u>2</u>]. There is no next greater element, so the answer is -1.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [2,4], nums2 = [1,2,3,4]
<strong>Output:</strong> [3,-1]
<strong>Explanation:</strong> The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,<u>2</u>,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,<u>4</u>]. There is no next greater element, so the answer is -1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length &lt;= nums2.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 10<sup>4</sup></code></li>
	<li>All integers in <code>nums1</code> and <code>nums2</code> are <strong>unique</strong>.</li>
	<li>All the integers of <code>nums1</code> also appear in <code>nums2</code>.</li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you find an <code>O(nums1.length + nums2.length)</code> solution?


<p>

Explnation:

Bilkul. Is code ko **line-by-line dry run** karte hain, ekdum simple way mein.

Let's take the standard example:

```cpp
nums1 = [4, 1, 2]
nums2 = [1, 3, 4, 2]
```

Question ka meaning:

> `nums2` mein har number ke **right side ka first greater number** find karo.

So manually:

```text
1 → 3
3 → 4
4 → -1
2 → -1
```

Therefore for `nums1 = [4,1,2]`:

```text
4 → -1
1 → 3
2 → -1

Answer = [-1, 3, -1]
```

Now code kya kar raha hai, let's feel it.

---

# 1. Initially

```cpp
stack<int> monotonicStack;
unordered_map<int, int> nextGreaterMap;
```

Both empty:

```text
Stack: []
Map:   {}
```

---

# 2. `nums2` reverse hota hai

Original:

```text
nums2 = [1, 3, 4, 2]
```

Then:

```cpp
reverse(nums2.begin(), nums2.end());
```

Becomes:

```text
nums2 = [2, 4, 3, 1]
```

### Why?

Because original array mein hume **right side** dekhna hai.

Original:

```text
1  3  4  2
↑
```

For `1`, right mein `3,4,2` hain.

Reverse karne ke baad hum left-to-right chal sakte hain:

```text
2  4  3  1
↑
```

So original right side ab processing mein "pehle" aa gayi.

---

# 3. First element = `2`

```cpp
currentNum = 2
```

Stack:

```text
[]
```

Code:

```cpp
while (!stack.empty() && stack.top() < currentNum)
```

Stack empty hai, so while doesn't run.

Then:

```cpp
if (!stack.empty())
```

Again empty → nothing.

Then:

```cpp
stack.push(2);
```

Now:

```text
Stack: [2]
Map:   {}
```

Meaning:

> Abhi `2` ko kisi future smaller number ke liye greater candidate bana ke rakha hai.

---

# 4. Next = `4`

```cpp
currentNum = 4
```

Current stack:

```text
[2]
```

Check:

```cpp
stack.top() < currentNum
2 < 4 ✅
```

So:

```cpp
stack.pop();
```

`2` bahar.

```text
Stack: []
```

Now stack empty.

So `4` ka koi greater element nahi mila.

Then:

```cpp
stack.push(4);
```

Now:

```text
Stack: [4]
Map: {}
```

---

# 5. Next = `3`

```cpp
currentNum = 3
```

Stack:

```text
[4]
```

Check:

```text
4 < 3 ❌
```

So pop nahi karenge.

Now:

```cpp
if (!stack.empty())
```

Stack empty nahi hai ✅

Therefore:

```cpp
nextGreaterMap[3] = stack.top();
```

So:

```text
nextGreaterMap[3] = 4
```

Map:

```text
3 → 4
```

Then:

```cpp
stack.push(3);
```

Stack:

```text
[4, 3]
```

So ab:

```text
Stack: [4, 3]
Map:   {3 → 4}
```

---

# 6. Next = `1`

```cpp
currentNum = 1
```

Stack:

```text
[4, 3]
```

Top = `3`

Check:

```text
3 < 1 ❌
```

No pop.

So:

```cpp
nextGreaterMap[1] = 3;
```

Map:

```text
3 → 4
1 → 3
```

Then push `1`:

```text
Stack: [4, 3, 1]
```

---

# 7. nums2 processing finished

We have:

```text
Reversed nums2:
[2, 4, 3, 1]
```

And map contains:

```text
3 → 4
1 → 3
```

What about `2` and `4`?

Their next greater element doesn't exist.

So map mein entry hi nahi hai.

Conceptually:

```text
1 → 3
3 → 4
4 → nothing
2 → nothing
```

---

# 8. Now `nums1` process hota hai

```cpp
nums1 = [4, 1, 2]
```

### First: `4`

Check map:

```cpp
nextGreaterMap.find(4)
```

`4` map mein nahi hai.

Therefore:

```cpp
result.push_back(-1);
```

Result:

```text
[-1]
```

---

### Second: `1`

Map mein:

```text
1 → 3
```

So:

```cpp
result.push_back(3);
```

Result:

```text
[-1, 3]
```

---

### Third: `2`

Map mein `2` nahi hai.

So:

```cpp
result.push_back(-1);
```

Final:

```text
[-1, 3, -1]
```

---

# The whole dry run in one table

| Current | Stack before | Action | Map |
|---|---|---|---|
| `2` | `[]` | push `2` | `{}` |
| `4` | `[2]` | pop `2`, push `4` | `{}` |
| `3` | `[4]` | `4` is greater → `3→4`, push `3` | `{3→4}` |
| `1` | `[4,3]` | `3` is greater → `1→3`, push `1` | `{3→4, 1→3}` |

Then:

```text
nums1 = [4,1,2]

4 → -1
1 → 3
2 → -1

answer = [-1,3,-1]
```

---

# The most important thing to understand

The **stack is basically storing possible greater elements**.

Suppose:

```text
Stack = [4, 3, 1]
```

and current number is `1`.

Top is `3`.

Since:

```text
3 > 1
```

we immediately know:

```text
next greater of 1 = 3
```

But suppose current is `4` and stack top is `2`:

```text
2 < 4
```

Then `2` can **never** be the next greater for `4`, so we throw it away:

```cpp
stack.pop();
```

That's the core idea of the **monotonic stack**.

### Think of it like this:

```text
Current number
     ↓
Can stack top beat me?

YES → that's my next greater
NO  → remove stack top
```

And that's why this algorithm is **O(n)** instead of repeatedly scanning to the right.

One small detail: `reverse(nums2...)` actually modifies the `nums2` vector itself. That doesn't hurt this LeetCode solution because `nums2` isn't needed afterward.

If you understand **why `4` pops `2`, but `3` does NOT pop `4`**, you've basically understood the heart of this problem.
	
</p>
