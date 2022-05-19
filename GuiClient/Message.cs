using Newtonsoft.Json;
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

        // deserialization
        public Message(String buffer)
        {
            // Add deserialization here
        }

        // serialization
        override public String ToString()
        {
            String buffer = "";
            buffer += (char)((byte)this.code);
            String jsonData = JsonConvert.SerializeObject(this.data);
            buffer += intToBytes(jsonData.Length);
            buffer += jsonData;
            return buffer;
        }

        private int code { get; }
        private Dictionary<String, String> data { get; }

        // return number as a string of bytes.
        private String intToBytes(int num) {
            String output = "";
            byte[] lenBytes = BitConverter.GetBytes(num);
            for (int i = 0; i < lenBytes.Length; i++) {
                output += ((char)lenBytes[i]);
            }
            return output;
        }
    }
}
