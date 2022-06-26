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
    public class GameStartedException : Exception
    {
        public GameStartedException()
        {
        }

        public GameStartedException(string message)
            : base(message)
        {
        }

        public GameStartedException(string message, Exception inner)
            : base(message, inner)
        {
        }
    }

    public class GameNotFinishedException : Exception
    {
        public GameNotFinishedException()
        {
        }

        public GameNotFinishedException(string message)
            : base(message)
        {
        }

        public GameNotFinishedException(string message, Exception inner)
            : base(message, inner)
        {
        }
    }
}
