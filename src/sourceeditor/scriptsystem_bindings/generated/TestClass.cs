using System;
using System.IO;
using ScriptSystem.Bindings;

public class TestClass
{ 
	public static void TestBindings()
	{
		ScriptSystemBindings.Msg("C# Testing Msg()\n");
		ScriptSystemBindings.Warning("C# Testing Warning()\n");
		ScriptSystemBindings.Log("C# Testing Log()\n");
	}
}
