using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GuiClient
{
    internal class Message
    {   
        public Message(int _code, Dictionary<String, String> _data) {
            code = _code;
            data = _data;
        }

        public Message(String buffer)
        {
            // Add deserialization here
        }

        override public String ToString()
        {
            // Add serialization here
            return "";
        }

        private int code { get; }
        private Dictionary<String, String> data { get; }

    }
}
