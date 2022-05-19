using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GuiClient
{
    internal class Message
    {
        public int _code;
        public Dictionary<String, String> _data;
        
        public Message(int code, Dictionary<String, String> data) {
            _code = code;
            _data = data;
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
    }
}
