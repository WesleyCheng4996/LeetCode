<h2><a href="https://leetcode.com/problems/unique-morse-code-words/">804. Unique Morse Code Words</a></h2><h3>Easy</h3><hr><div><p style="text-align: start;">International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows:</p>

<ul>
	<li><code>'a'</code><font _mstmutation="1"> maps to ,</font><code>".-"</code></li>
	<li><code>'b'</code><font _mstmutation="1"> maps to ,</font><code>"-..."</code></li>
	<li><code>'c'</code><font _mstmutation="1"> maps to , and so on.</font><code>"-.-."</code></li>
</ul>

<p style="text-align: start;"><font _mstmutation="1">For convenience, the full table for the  letters of the English alphabet is given below:</font><code>26</code></p>

<pre>[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]</pre>

<p style="text-align: start;"><font _mstmutation="1">Given an array of strings  where each word can be written as a concatenation of the Morse code of each letter.</font><code>words</code></p>

<ul>
	<li><font _mstmutation="1">For example,  can be written as , which is the concatenation of , , and . We will call such a concatenation the <strong _mstmutation="1">transformation</strong> of a word.</font><code>"cab"</code><code>"-.-..--..."</code><code>"-.-."</code><code>".-"</code><code>"-..."</code></li>
</ul>

<p style="text-align: start;">Return <em>the number of different <strong>transformations</strong> among all words we have</em>.</p>

<p>&nbsp;</p>
<p style="text-align: start;"><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> words = ["gin","zen","gig","msg"]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The transformation of each word is:
"gin" -&gt; "--...-."
"zen" -&gt; "--...-."
"gig" -&gt; "--...--."
"msg" -&gt; "--...--."
There are 2 different transformations: "--...-." and "--...--.".
</pre>

<p style="text-align: start;"><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> words = ["a"]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p style="text-align: start;"><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 12</code></li>
	<li><code>words[i]</code><font _mstmutation="1"> consists of lowercase English letters.</font></li>
</ul>
</div>