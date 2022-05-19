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
            // first byte is the message code, then there are four length bytes for sockets stuff and then the json
            code = (int)(byte)buffer[0];
            data = JsonConvert.DeserializeObject<Dictionary<String, String>>(buffer.Substring(5));
        }

        // serialization
        override public String ToString()
        {
            String buffer = "";
            buffer += (char)((byte)code);
            String jsonData = JsonConvert.SerializeObject(data);
            buffer += IntToBytes(jsonData.Length);
            buffer += jsonData;
            return buffer;
        }

        private int code { get; }
        private Dictionary<String, String> data { get; }

        // return number as a string of bytes.
        private String IntToBytes(int num) {
            String output = "";
            byte[] lenBytes = BitConverter.GetBytes(num);
            for (int i = 0; i < lenBytes.Length; i++) {
                output += ((char)lenBytes[i]);
            }
            return output;
        }
    }
}
