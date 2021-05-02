using System;
using System.IO;
using ScriptSystem.Bindings;

public class TestClass
{ 
	public static void TestBindings()
	{
		ScriptSystemBindings.Msg("Hello from C# and Mono :)\n");

		if (SourceCommandLine.FindParm("-testbeans") == 1)
		{
			ScriptSystemBindings.Msg("WE GOT THE BEANS\n");
		}
	}
}
