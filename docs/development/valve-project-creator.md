# Adding a new tool

Unlike most source mods, our files are project definitions are not stored in `src/vpc_scripts/projects.vgc`, we store ours in `src/sourceeditor/vpc_scripts/projects.vgc` as this makes it easier for us to see what is being actually added in our project.

## Adding a new project

To add a new project, you first need to make a VPC script for it, you can find information about that [on the Valve Developer Wiki](https://developer.valvesoftware.com/wiki/Editing_VPC_scripts).

To do: Add information here on how to create a VPC script

After you have made your VPC script, you will need to add it to our project.vgc. Navigate to `src/sourceeditor/vpc_scripts/projects.vgc` and add a value following this template

```
$Project "<your project name>"
{
	"sourceeditor/<path to your tool/project>.vpc" [$WIN32]
}
```

Once you have done this you will need to add your project to our group which makes VPC add it to a solution so you can compile it. To do this, open the `groups.vgc` file and add a new entry into `sourceeditor` like so

```
$Group "sourceeditor"
{
	"sourceeditor_launcher"
    "sourceeditor_dll
    "<your project name>"
}
```

When this is done, you can now run `createsourceeditor.bat` in the the root directory and you can now start editing your project aswell as compile it.