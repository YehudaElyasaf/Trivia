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
        public Message(int _code, Dictionary<string, string> _data) {
            code = _code;
            data = _data;
        }

        // deserialization
        public Message(string buffer)
        {
            // first byte is the message code, then there are four length bytes for sockets stuff and then the json
            code = (int)(byte)buffer[0];
            data = JsonConvert.DeserializeObject<Dictionary<string, string>>(buffer.Substring(Const.HEADERS_LENGTH));
        }

        // serialization
        override public string ToString()
        {
            string buffer = "";
            buffer += (char)((byte)code);
            string jsonData = JsonConvert.SerializeObject(data);
            buffer += IntToBytes(jsonData.Length);
            buffer += jsonData;
            return buffer;
        }

        private int code;
        private Dictionary<string, string> data;

        // return number as a string of bytes.
        private string IntToBytes(int num) {
            string output = "";
            byte[] lenBytes = BitConverter.GetBytes(num);
            for (int i = 0; i < lenBytes.Length; i++) {
                output += ((char)lenBytes[i]);
            }
            return output;
        }

        //getters
        public int GetCode() { return code; }
        public Dictionary<string, string> GetData() { return data; }
    }
}
