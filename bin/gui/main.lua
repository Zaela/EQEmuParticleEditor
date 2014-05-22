
local lfs = require "lfs"

function assert(result, msg)
	if result then return result end
	local err = iup.messagedlg{buttons = "OK", dialogtype = "ERROR", title = "Error", value = msg}
	iup.Popup(err)
	iup.Close()
end

function error_popup(msg)
	local err = iup.messagedlg{buttons = "OK", dialogtype = "ERROR", title = "Error", value = msg}
	iup.Popup(err)
	iup.Destroy(err)
end

local display = require "gui/display"
local list = require "gui/list"

local function SetSearchFolder()
	local dlg = iup.filedlg{title = "Select EDD File", dialogtype = "FILE",
		extfilter = "EDD Files (*.edd)|*.edd|All Files|*.*|", directory = lfs.currentdir()}
	iup.Popup(dlg)
	if dlg.status == "0" then
		local path = dlg.value
		if path then
			search_path = path
			UpdateList(path)
			local f = assert(io.open("gui/settings.lua", "w+"))
			f:write("\nreturn \"".. (path:gsub("\\", "\\\\")) .."\"\n")
			f:close()
		end
	end
end

local function LoadSettings()
	local settings = loadfile("gui/settings.lua")
	if settings then
		local path = settings()
		if path then
			search_path = path
			UpdateList(path)
			return
		end
	end
end

LoadSettings()
LoadSettings = nil

local menu = iup.menu{
	iup.submenu{
		title = "&File";
		iup.menu{
			iup.item{title = "Open EDD File", action = SetSearchFolder},
			iup.separator{},
			iup.item{title = "&Quit", action = function() return iup.CLOSE end},
		},
	},
}

local window = assert(iup.dialog{iup.hbox{list, display; nmargin = "10x10", gap = 10};
	title = "EQEmu Particle Editor v0.1", menu = menu})

function window:k_any(key)
	if key == iup.K_ESC then
		return iup.CLOSE
	end
end

window:show()
iup.MainLoop()

iup.Close()
