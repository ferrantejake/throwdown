/**
 * Watch-files
 * If you're curious what this is, check out
 * my other project:
 * https://github.com/ferrantejake/watch-files
 */

var gulp = require('gulp'),
    util = require('gulp-util'),
    project = require('./gulp.json'),
    path = require('path'),
    exec = require('child_process').exec;

gulp.task('default', ['watch'], (cb) => {});

gulp.task('watch', (cb) => {
    // wait for file changes
    var watcher = gulp.watch(project.src);
    watcher.on('change', (event) => {
        util.log(`Rebuilding ${path.basename(event.path)}`);
        var filePath = event.path;
        var fileName = path.basename(filePath);

        // run child process cc command
        exec('cc ' + filePath, function (err) {
            if (err) {
                util.log(err.message)
            } else {
                util.log(`[${fileName}] complete, no errors`)
            }
        });
    });
});

