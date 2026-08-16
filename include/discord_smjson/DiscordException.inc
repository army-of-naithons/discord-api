#if defined _DiscordException_included_
  #endinput
#endif
#define _DiscordException_included_

methodmap DiscordException __nullable__ /* < Exception */
{
	public DiscordException(const char[] error, any ...)
	{
		char buffer[1024];
		SetGlobalTransTarget(LANG_SERVER);
		VFormat(buffer, sizeof(buffer), error, 2);
		//return view_as<DiscordException>(LogError("Discord Exception: %s", buffer)); // вызывало "casting a void function is illegal" в компиляторе 1.12+
		LogError("Discord Exception: %s", buffer);
		return null;
	}
}