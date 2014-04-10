// http://www.careercup.com/question?id=4840369632051200
// I believe this is not a typical interview question. You must've told them you know LINQ, before you're given this one.
// I've never learnt LINQ before, only basic knowledge of C# is not enough to solve this problem.
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp
{
    class Person
    {
        public string title;
        public string alias;
        public List<Person> subordinate;

        public Person(string title, string alias)
        {
            this.title = title;
            this.alias = alias;
            subordinate = new List<Person>();
        }
    }

    class Solution
    {
        Person search(string title, string alias, Person source) {
            if (source.title == title) {
                return source.alias == alias ? source : null;
            }

            Person result;
            foreach(Person sub_source in source.subordinate)
            {
                result = search(title, alias, sub_source);
                if (result != null)
                {
                    return result;
                }
            }

            return null;
        }
    }
}