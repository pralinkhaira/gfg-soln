<h2><a href="https://www.geeksforgeeks.org/problems/lru-cache/1?page=1&difficulty=Hard&sortBy=submissions">LRU Cache</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Design a data structure that works like a LRU Cache. Here <strong>cap</strong>&nbsp;denotes&nbsp;the capacity of the cache and Q denotes the number of queries. Query can be </span><span style="font-size:18px">of two types:</span></p>

<ol>
	<li><span style="font-size:18px"><strong>SET</strong> <strong>x</strong> <strong>y</strong>: sets the value of the key <strong>x</strong> with value <strong>y</strong> </span></li>
	<li><span style="font-size:18px"><strong>GET</strong> <strong>x</strong>: gets the key of <strong>x</strong> if present else returns <strong>-1</strong>.</span></li>
</ol>

<p><br>
<span style="font-size:18px">The LRUCache class has two methods <strong>get</strong>() and <strong>set</strong>() which are defined as follows.</span></p>

<ol>
	<li><span style="font-size:18px"><strong>get(key)</strong>: returns the value of the key if it&nbsp;already exists in the cache otherwise returns <strong>-1.</strong></span></li>
	<li><span style="font-size:18px"><strong>set(key, value)</strong>: if the key is already present, update its value. If not present, add the key-value pair to the cache.&nbsp;If the cache reaches its capacity it should invalidate&nbsp;the least recently used item before inserting the new item.</span></li>
	<li><span style="font-size:18px">In the <strong>constructor</strong> of the class the capacity of the cache should be initialized.</span></li>
</ol>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>cap = 2
Q = 2
Queries = SET 1 2 GET 1
<strong>Output: </strong>2<strong>
Explanation: 
</strong>Cache Size = 2

SET 1 2 GET 1
SET 1 2 : 1 -&gt; 2

GET 1 : Print the value corresponding
to Key 1, ie 2.</span>
</pre>

<p><br>
<span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>cap = 2
Q = 8
Queries = SET 1 2 SET 2 3 SET 1 5
SET 4 5 SET 6 7 GET 4 SET 1 2 GET 3
<strong>Output: </strong>5 -1<strong>
Explanation: 
</strong>Cache Size = 2
SET 1 2 : 1 -&gt; 2

SET 2 3 : 1 -&gt; 2, 2 -&gt; 3 (the most recently 
used one is kept at the rightmost position)&nbsp;

SET 1 5 : 2 -&gt; 3, 1 -&gt; 5

SET 4 5 : 1 -&gt; 5, 4 -&gt; 5 (Cache size is 2, hence 
we delete the least recently used key-value pair)

SET 6 7 : 4 -&gt; 5, 6 -&gt; 7&nbsp;

GET 4 : Prints 5 (The cache now looks like
6 -&gt; 7, 4-&gt;5)

SET 1 2 : 4 -&gt; 5, 1 -&gt; 2 
(Cache size is 2, hence we delete the least 
recently used key-value pair)

GET 3 : No key value pair having 
key = 3. Hence, -1 is printed.
</span>
</pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Complete the constructor and get(), and set() methods of the class LRUcache.&nbsp;</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(1) for both&nbsp;<strong>get()&nbsp;</strong>and <strong>set().</strong><br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(1) for&nbsp;both&nbsp;<strong>get()&nbsp;</strong>and&nbsp;<strong>set().&nbsp;</strong><br>
(Although, you may use extra space for cache storage and implementation purposes).</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= cap&nbsp;&lt;= 10^3<br>
1 &lt;= Q &lt;= 10^5<br>
1 &lt;= x, y &lt;= 10^4</span></p>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Paytm</code>&nbsp;<code>Zoho</code>&nbsp;<code>Flipkart</code>&nbsp;<code>Morgan Stanley</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>OYO Rooms</code>&nbsp;<code>Samsung</code>&nbsp;<code>Snapdeal</code>&nbsp;<code>Hike</code>&nbsp;<code>MakeMyTrip</code>&nbsp;<code>Ola Cabs</code>&nbsp;<code>Visa</code>&nbsp;<code>Walmart</code>&nbsp;<code>Goldman Sachs</code>&nbsp;<code>Adobe</code>&nbsp;<code>Google</code>&nbsp;<code>Yahoo</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>doubly-linked-list</code>&nbsp;<code>Hash</code>&nbsp;<code>Queue</code>&nbsp;<code>Design-Pattern</code>&nbsp;<code>Data Structures</code>&nbsp;