using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GuiClient
{
    public class NoDataToReadException : Exception
    {
        public NoDataToReadException()
        {
        }

        public NoDataToReadException(string message)
            : base(message)
        {
        }

        public NoDataToReadException(string message, Exception inner)
            : base(message, inner)
        {
        }
    }
}
