
SRC_DIR=$1
DST_DIR=$2

if [ ! -d "$SRC_DIR" ]; then
    echo "source dir not exist"
    exit 1
fi

if [ ! -d "$DST_DIR" ]; then
    mkdir -p "$DST_DIR"
fi

# for file in "$SRC_DIR"/* ; do
#     cp "$file" "$DST_DIR"
# done

cp $SRC_DIR/* "$DST_DIR"

echo "backup created successfully"