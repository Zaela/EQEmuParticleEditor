
local lfs = require "lfs"

local list = iup.list{visiblelines = 10, expand = "VERTICAL", visiblecolumns = 14}
local filter = iup.text{visiblecolumns = 13, value = ""}

function filter:valuechanged_cb()
	local data = main_list
	if data then
		FilterList(data)
	end
end

local pcall = pcall
local ipairs = ipairs

function UpdateList(path)
	list[1] = nil
	local s, main_data = pcall(data.Read, path)
	if s then
		main_list = main_data
		FilterList(main_data)
	end
end

local by_pos = {}
function FilterList(data)
	list[1] = nil
	list.autoredraw = "NO"
	local f = filter.value
	if f:len() > 0 then
		--make dot only match dot, not any and all characters
		f = f:gsub("%.", "%%%.")
		--make sure last char isn't a dangling % (will throw incomplete pattern error)
		if f:find("%%", -1) then
			f = f .. "%"
		end
		local i = 1
		for _, d in ipairs(data) do
			local name = d.name
			if name:find(f) then
				list[i] = name
				by_pos[i] = d
				i = i + 1
			end
		end
	else
		for i, d in ipairs(data) do
			list[i] = d.name
			by_pos[i] = d
		end
	end
	list.autoredraw = "YES"
end

function list:action(str, pos, state)
	if state == 1 then
		local sel = by_pos[pos]
		selection = sel
		UpdateDisplay(sel)
	end
end

function list:button_cb(button, pressed, x, y)
	if button == iup.BUTTON3 and pressed == 0 then
		local mx, my = iup.GetGlobal("CURSORPOS"):match("(%d+)x(%d+)")
		local menu = iup.menu{
			iup.item{title = "Add New Entry", action = NewParticle},
			iup.item{title = "Copy Selection", action = CopyParticle, active = selection and "YES" or "NO"},
		}
		iup.Popup(menu, mx, my)
		iup.Destroy(menu)
	end
end

return iup.vbox{iup.hbox{iup.label{title = "Filter"}, filter; alignment = "ACENTER", gap = 5}, list, edit_button;
	alignment = "ACENTER", gap = 5}
