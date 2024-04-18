<h2><a href="https://www.geeksforgeeks.org/problems/box-stacking/1?page=4&difficulty=Hard&sortBy=submissions">Box Stacking</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">You are given a set of <strong>N</strong>&nbsp;types of rectangular 3-D boxes, where the ith box has height <strong>h</strong>, width <strong>w</strong> and length&nbsp;<strong>l</strong>. Your task is to create a stack of boxes which is as tall as possible, but you can only stack a box on top of another box if the <strong>dimensions</strong> of the 2-D base of the lower box are each strictly larger than those of the 2-D base of the higher box. Of course, you can rotate a box so that any side functions as its base.It is also allowable to use multiple instances of the same type of box. Your task is to complete the function <strong>maxHeight</strong> which returns the&nbsp;height of the highest possible stack so formed.</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Note:&nbsp;</strong><br>
Base of the lower box should be strictly larger than that of the new box we're going to place. This is in terms of both length and width, not just in terms of area. So, two boxes with same base cannot be placed one over the other.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
n = 4
height[] = {4,1,4,10}
width[] = {6,2,5,12}
length[] = {7,3,6,32}
<strong>Output:</strong> 60
<strong>Explanation: </strong>One way of placing the boxes is
as follows in the bottom to top manner:
(Denoting the boxes in (l, w, <strong>h</strong>) manner)
(12, 32, <strong>10</strong>) (10, 12, <strong>32</strong>) (6, 7, <strong>4</strong>) 
(5, 6, <strong>4</strong>) (4, 5, <strong>6</strong>) (2, 3, <strong>1</strong>) (1, 2, <strong>3</strong>)
Hence, the total height of this stack is
10 + 32 + 4 + 4 + 6 + 1 + 3 = 60.
No other combination of boxes produces a
height greater than this.</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong>:
n = 3
height[] = {1,4,3}
width[] = {2,5,4}
length[] = {3,6,1}
<strong>Output:</strong> 15</span>
<span style="font-size:18px"><strong>Explanation: </strong>One way of placing the boxes is
as follows in the bottom to top manner:
(Denoting the boxes in (l, w, <strong>h</strong>) manner)
(5, 6, <strong>4</strong>) (4, 5, <strong>6</strong>) (3, 4, <strong>1</strong>), (2, 3, <strong>1</strong>) 
(1, 2, <strong>3</strong>).
Hence, the total height of this stack is
4 + 6 + 1 + 1 + 3 = 15
No other combination of boxes produces a
height greater than this.</span>
</pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>maxHeight()</strong>&nbsp;which takes three arrays&nbsp;height[],&nbsp;width[],&nbsp;length[], and N as a number of boxes and returns&nbsp;the&nbsp;<strong>highest possible stack height</strong>&nbsp;which could be formed.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity</strong> : O(N*N)<br>
<strong>Expected Auxiliary Space</strong>: O(N)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1&lt;= N &lt;=100<br>
1&lt;= l,w,h &lt;=100</span></p>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Codenation</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Algorithms</code>&nbsp;