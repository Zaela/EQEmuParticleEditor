
edit_button = iup.button{title = "Commit Changes", padding = "10x0", active = "NO"}
local button = edit_button

local function Edited()
	button.active = "YES"
end

local function EnterKey(self, key)
	if key == iup.K_CR and edit_button.active == "YES" then
		button:action()
	end
end

local function int()
	return iup.text{visiblecolumns = 12, mask = iup.MASK_INT, action = Edited, k_any = EnterKey}
end

local function float()
	return iup.text{visiblecolumns = 12, mask = iup.MASK_FLOAT, action = Edited, k_any = EnterKey}
end

local f = {
	id = iup.text{visiblecolumns = 12, readonly = "YES"},
	filename = iup.text{visiblecolumns = 12, action = Edited, k_any = EnterKey},
	field1 = int(), field2 = int(), field3 = int(), field4 = int(), field5 = int(), field6 = int(),
	field7 = float(), total_scale = float(), density_relatedA = int(), density_relatedB = int(),
	density = float(), emission_delayA = float(), emission_delayB = float(), fadeout_time = float(),
	particle_scaleA = float(), particle_scaleB = float(), field17 = float(), field18 = float(),
	field19 = int(), field20 = float(), x_axis_scale = float(), z_axis_scale = float(),
	translation_x = float(), translation_y = float(), translation_z = float(), field26 = float(),
	field27 = float(), image_stretch = float(), field29 = float(), red_tint1 = int(), green_tint1 = int(),
	blue_tint1 = int(), red_tint2 = int(), green_tint2 = int(), blue_tint2 = int(), field36 = float(),
	field37 = float(), field38 = float(), field39 = float(), field40 = float(), field41 = float(),
	field42 = float(), field43 = float(), field44 = float(), field45 = float(), field46 = float(),
	field47 = float(), field48 = float(), field49 = float(), field50 = float(), field51 = float(),
	field52 = float(), image_segments = int(), rotation_speed = float(), field55 = float(), field56 = float(),
	field57 = float(), field58 = float(), field59 = float(), field60 = float(), field61 = float(),
	field62 = float(), field63 = float(), field64 = float(), field65 = float(), field66 = float(),
	field67 = float(), field68 = float(), field69 = float(), field70 = float(), field71 = int(),
	field72 = float(), field73 = float(), field74 = float(), field75 = float(), field76 = int(),
	field77 = float(), field78 = float(), field79 = float(), field80 = int(),
}

int = nil
float = nil

local function e(name)
	return iup.label{title = name}
end

local grid1 = iup.gridbox{
	e"Effective ID", f.id, e"Filename", f.filename, e"Field1", f.field1, e"Field2", f.field2,
	e"Field3", f.field3, e"Field4", f.field4, e"Field5", f.field5, e"Field6", f.field6,
	e"Field7", f.field7, e"Total Scale", f.total_scale, e"Density A", f.density_relatedA,
	e"Density B", f.density_relatedB, e"Density C", f.density, e"Delay A", f.emission_delayA,
	e"Delay B", f.emission_delayB, e"Delay C (Fadeout)", f.fadeout_time, e"Particle Scale A", f.particle_scaleA,
	e"Particle Scale B", f.particle_scaleB, e"Max at Once", f.field17, e"Opacity", f.field18, e"Movement Style", f.field19;
	numdiv = 2, orientation = "HORIZONTAL", homogeneouslin = "YES",
	gapcol = 10, gaplin = 8, alignmentlin = "ACENTER", sizelin = 15
}

local grid2 = iup.gridbox{
	e"Initial Distribution", f.field20, e"Scale A", f.x_axis_scale, e"Scale B", f.z_axis_scale,
	e"Translation X", f.translation_x, e"Translation Y", f.translation_y, e"Translation Z", f.translation_z,
	e"Field26", f.field26, e"Field27", f.field27, e"Image Stretch", f.image_stretch, e"Field29", f.field29,
	e"Red Tint 1", f.red_tint1, e"Green Tint 1", f.green_tint1, e"Blue Tint 1", f.blue_tint1,
	e"Red Tint 2", f.red_tint2, e"Green Tint 2", f.green_tint2, e"Blue Tint 2", f.blue_tint2,
	e"Movement Speed A", f.field36, e"Movement Speed B", f.field37, e"Movement Speed C", f.field38, e"Stray X", f.field40, e"Stray Y", f.field39;
	numdiv = 2, orientation = "HORIZONTAL", homogeneouslin = "YES",
	gapcol = 10, gaplin = 8, alignmentlin = "ACENTER", sizelin = 16
}

local grid3 = iup.gridbox{
	e"Stray Z", f.field41, e"Spread X", f.field43, e"Spread Y", f.field42, e"Spread Z", f.field44, e"Distribution X", f.field45,
	e"Distribution Y", f.field46, e"Distribution Z", f.field47, e"Field48", f.field48, e"Field49", f.field49, e"Field50", f.field50,
	e"Field51", f.field51, e"Field52", f.field52, e"Image Segments", f.image_segments, e"Rotation Speed", f.rotation_speed,
	e"Field55", f.field55, e"Field56", f.field56, e"Field57", f.field57, e"Field58", f.field58, e"Field59", f.field59,
	e"Field60", f.field60, e"Field61", f.field61;
	numdiv = 2, orientation = "HORIZONTAL", homogeneouslin = "YES",
	gapcol = 10, gaplin = 8, alignmentlin = "ACENTER", sizelin = 12
}

local grid4 = iup.gridbox{
	e"Field62", f.field62, e"Field63", f.field63, e"Field64", f.field64, e"Field65", f.field65, e"Field66", f.field66,
	e"Field67", f.field67, e"Field68", f.field68, e"Field69", f.field69, e"Field70", f.field70, e"Field71", f.field71,
	e"Stretch X", f.field72, e"Stretch Y", f.field73, e"Stretch Z", f.field74, e"Field75", f.field75, e"Field76", f.field76,
	e"Field77", f.field77, e"Field78", f.field78, e"Field79", f.field79, e"Field80", f.field80;
	numdiv = 2, orientation = "HORIZONTAL", homogeneouslin = "YES",
	gapcol = 10, gaplin = 8, alignmentlin = "ACENTER", sizelin = 10
}

e = nil

local tonumber = tonumber
local pcall = pcall

function button:action()
	local sel = selection
	local path = search_path
	if not sel or not path or not main_list then return end

	for k, v in pairs(f) do
		if k == "filename" then
			sel.filename = v.value
		else
			sel[k] = tonumber(v.value)
		end
	end

	local s, err = pcall(data.Write, path .. "\\ActorEmittersNew.edd", main_list, sel)
	if s then
		button.active = "NO"
		return
	end
	error_popup(err)
end

function UpdateDisplay(d)
	for k, v in pairs(f) do
		v.value = d[k]
	end
	button.active = "NO"
end

function ClearDisplay()
	for _, field in pairs(f) do
		field.value = ""
	end
	button.active = "NO"
end

function NewParticle()
	local ml = main_list
	local path = search_path
	if not ml or not path then return end

	local name
	local input = iup.text{visiblecolumns = 12, nc = 63}
	local getname
	local but = iup.button{title = "Done", action = function() name = tostring(input.value) getname:hide() end}
	getname = iup.dialog{iup.vbox{
		iup.label{title = "Please enter a name to identify the new particle entry:"},
		input, but, gap = 12, nmargin = "15x15", alignment = "ACENTER"};
		k_any = function(self, key) if key == iup.K_CR then but:action() end end}
	iup.Popup(getname)
	iup.Destroy(getname)

	if not name then return end

	local d = {}
	for k in pairs(f) do
		d[k] = 0
	end
	local id = #ml + 1
	d.filename = ""
	d.id = id
	d.name = name
	d.offset = 0
	ml[id] = d

	local s, err = pcall(data.Write, path .. "\\ActorEmittersNew.edd", main_list, d)
	if s then
		FilterList(ml)
		return
	end
	error_popup(err)
end

return iup.hbox{grid1, grid2, grid3, grid4; gap = 5, nmargin = "10x10"}
