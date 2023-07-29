# Miguelio Rock

## Flashing

qmk flash -kb miguelio/rock -km default

# Compile .uf2 to michi rp2040

qmk compile -kb miguelio/rock -km default -e CONVERT_TO=michi