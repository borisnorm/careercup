// http://www.careercup.com/question?id=5377673471721472
// Answer:
//	The genenral practice of splitting queries across multiple machine, would require two parts:
//		1. convert the query to a digital sign, possibly an integer.
//		2. modulo it by the number of machines in a cluster, this process may be multi-layered.
//	Other scheduling strategies may affect the result of splitting, but I think modulo will be a simple and balanced way to split the queries.
int main()
{
	return 0;
}