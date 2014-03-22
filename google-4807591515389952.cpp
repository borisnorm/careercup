// http://www.careercup.com/question?id=4807591515389952
// What would happen if you have only one server for a web cache (a web browser cache whose key is url and value is the loaded content of the webpage) but huge numbers of clients? And how would you solve it? Assume the cache is implemented with a hashmap and a linkedlist.
// Answer: Well, I guess the cache can be considered a hash table, using chaining to handle collisions. LRU cache will be better. Despite the cache, with huge number of requests, the cache will be constantly flushed. It would still cause the server to crash. If the system is not so "dynamic", perhaps browser cache will help to reduce a little stress for the server-side cache.
int main()
{
	return 0;
}