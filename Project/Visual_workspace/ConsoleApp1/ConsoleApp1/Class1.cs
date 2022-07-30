using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Class1
    {
        int id { get; set; }
        String name { get; set; }
        internal void setName(int id,String Name)
        {
            this.id = id;
            this.name = Name;
            return;
        }
        internal void printMsg()
        {
            Console.WriteLine("id is"+id);
            Console.WriteLine("name is"+name);
        }
    }
}
